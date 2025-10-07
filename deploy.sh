#!/bin/sh

set -e

BINARY_NAME=ak_doorbell
OUTPUT_BIN=./build/${BINARY_NAME}
OUTPUT_DIR=/tmp

if [ $# -lt 1 ]; then
  echo "Usage: $0 <host> [user:-root] [pass:-]"
  exit 1
fi

REMOTE_HOST=$1
REMOTE_USER=${2:-root}
REMOTE_PASS=${3:-}

curl -T ${OUTPUT_BIN} ftp://${REMOTE_HOST}${OUTPUT_DIR}/ --user "${REMOTE_USER}:${REMOTE_PASS}"

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
    send "chmod +x ${OUTPUT_DIR}/${BINARY_NAME} && echo done\r"
    expect "done"
    send "exit\r"
  }
}
expect eof
EOF