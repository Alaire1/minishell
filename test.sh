#!/bin/bash
printf 'cmd1 | cmd2 | cmd3 | cmd4 | cmd5 | cmd6 | cmd7 | cmd8' | grep -o '|' | wc -l
