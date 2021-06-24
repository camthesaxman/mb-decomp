#!/bin/bash

OBJDUMP="sh4-linux-gnu-objdump -D -bbinary -m sh4 -EL"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS baserom.bin > baserom.dump
$OBJDUMP $OPTIONS monkeyball.bin > monkeyball.dump
diff -u --color=always baserom.dump monkeyball.dump
