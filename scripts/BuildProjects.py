#!/usr/bin/env python3

import subprocess

CONFIG = "debug"

subprocess.call(["bear", "--", "make", "config={}".format(CONFIG)])
