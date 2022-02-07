#!/usr/bin/env python3

import subprocess
import os

os.chdir(os.path.join(".", "scripts"))

subprocess.run([os.path.join("..", "vendor", "premake", "bin", "premake5"), "--file=../premake5.lua", "gmake2"])
