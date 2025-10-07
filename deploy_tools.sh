#!/bin/sh

set -e

GDB_ARCHIVE=gdb-static-slim-arm.tar.gz
GDB_DIR=/tmp/gdb

if [ $# -lt 1 ]; then
  echo "Usage: $0 <host> [user:-root] [pass:-]"
  exit 1
fi

REMOTE_HOST=$1
REMOTE_USER=${2:-root}
REMOTE_PASS=${3:-}

curl -T toolchain/${GDB_ARCHIVE} ftp://${REMOTE_HOST}/tmp/ --user "${REMOTE_USER}:${REMOTE_PASS}"

expect <<EOF
set timeout 30
spawn telnet ${REMOTE_HOST}
expect "anyka login:"
send "${REMOTE_USER}\r"
expect {
  "Password:" {
    send "${REMOTE_PASS}\r"
    exp_continue
  }
  "${REMOTE_USER}@" {
    send "mkdir -p ${GDB_DIR} && tar xvzf /tmp/${GDB_ARCHIVE} -C ${GDB_DIR} && rm -f /tmp/${GDB_ARCHIVE} && echo done \r"
    expect "done"
    send "exit\r"
  }
}
expect eof
EOF