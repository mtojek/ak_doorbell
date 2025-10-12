#!/bin/bash

set -eou pipefail

BASE_IMAGE=${1:-data/firmware/SRA_704MAHTOS_original}
OVERRIDE_DATA=${2:-data/override}
OUTPUT_IMAGE=${3:-SRA_704MAHTOS}

echo "Base firmware image: ${BASE_IMAGE}"
echo -n "MD5 sum: "
md5 -q ${BASE_IMAGE}
binwalk ${BASE_IMAGE}

tar tvzf ${BASE_IMAGE}
echo

WORK_DIR_UNTAR=`mktemp -d`
echo "Work dir untar: ${WORK_DIR_UNTAR}"
# FIXME delete WORK_DIR_UNTAR on trap

echo "Unpack image..."
tar xvzf ${BASE_IMAGE} -C ${WORK_DIR_UNTAR}
binwalk ${WORK_DIR_UNTAR}/app.sqsh4

WORK_DIR_UNSQUASH=`mktemp -d`
echo "Work dir unsquash: ${WORK_DIR_UNSQUASH}"

unsquashfs -d ${WORK_DIR_UNSQUASH} ${WORK_DIR_UNTAR}/app.sqsh4
find ${WORK_DIR_UNSQUASH} -type f -exec ls -la {} +

echo "Copy override files..."
cp -r ${OVERRIDE_DATA}/ ${WORK_DIR_UNSQUASH}
find ${WORK_DIR_UNSQUASH} -type f -exec ls -la {} +

echo "Squash files back..."
WORK_DIR_SQUASH=`mktemp -d`
echo "Work dir squash: ${WORK_DIR_SQUASH}"
cp -r ${WORK_DIR_UNTAR}/ ${WORK_DIR_SQUASH}
rm ${WORK_DIR_SQUASH}/app.sqsh4

mksquashfs ${WORK_DIR_UNSQUASH} ${WORK_DIR_SQUASH}/app.sqsh4 -comp xz -noappend
binwalk ${WORK_DIR_SQUASH}/app.sqsh4
find ${WORK_DIR_SQUASH} -type f -exec ls -la {} +

echo "Repack image..."
tar -cvzf ${OUTPUT_IMAGE} -C ${WORK_DIR_SQUASH} .

echo "Verify image..."
tar tvzf ${OUTPUT_IMAGE}
echo

echo "Cleanup"
rm -rf ${WORK_DIR_UNTAR}
rm -rf ${WORK_DIR_UNSQUASH}
rm -rf ${WORK_DIR_SQUASH}

echo "Done."
