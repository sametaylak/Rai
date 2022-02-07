#!/usr/bin/env python3

import os
import wget
import urllib
import shutil

PREMAKE_VERSION="5.0.0-alpha16"
PREMAKE_URL=f"https://github.com/premake/premake-core/releases/download/v{PREMAKE_VERSION}/premake-{PREMAKE_VERSION}-macosx.tar.gz"
PREMAKE_LICENSE_URL="https://raw.githubusercontent.com/premake/premake-core/master/LICENSE.txt"
PREMAKE_DIRECTORY="vendor/premake/bin"
PREMAKE_TAR_FILE="premake5.tar.gz"

os.chdir(os.path.join(".", "scripts"))
os.mkdir(os.path.join("..", PREMAKE_DIRECTORY))

urllib.request.urlretrieve(PREMAKE_URL, os.path.join("..", PREMAKE_DIRECTORY, PREMAKE_TAR_FILE))

shutil.unpack_archive(os.path.join("..", PREMAKE_DIRECTORY, PREMAKE_TAR_FILE), os.path.join("..", PREMAKE_DIRECTORY))

os.remove(os.path.join("..", PREMAKE_DIRECTORY, PREMAKE_TAR_FILE))
