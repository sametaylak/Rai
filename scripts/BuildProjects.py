#!/usr/bin/env python3

import sys
import os
import subprocess

CONFIG = "debug"

subprocess.call(["make", "config={}".format(CONFIG)])
