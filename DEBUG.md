# Remote debugging

1. Deploy statically compiled `gdb` tools:

```bash
./deploy_tools.sh
```

2. Deploy `ak_doorbell` binary:

```bash
./deploy.sh
```

3. Run `ak_doorbell` on the target device and wait for `gdbserver` to start listening:

```bash
/tmp/gdb/gdbserver :1234 /tmp/ak_doorbell
```

4. Use `gdb` to start the remote process:

```bash
gdb
(gdb) set architecture arm
(gdb) target remote <IP>:1234
(gdb) continue
```
