#!/usr/bin/env python

#*****************************************************************************
# ______  _                             ___  ___        _               
# | ___ \(_)                            |  \/  |       | |              
# | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
# | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
# | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
# \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
#                                 __/ |                                 
#                                |___/                                  
#                                                                       
# Copyright (C) 2019 Binary Maker - All Rights Reserved
#
# This program and the accompanying materials are made available
# under the terms described in the LICENSE file which accompanies
# this distribution.
# Written by Binary Maker <https://github.com/binarymaker>
#*****************************************************************************

import os
import argparse
import subprocess
import time
import json

def file_create(file_name, file_text):
    if(os.path.exists(file_name)):
        print("file exists", file_name)
    else:
        proj_file = open(file_name,'w')
        proj_file.write(file_text)
        proj_file.close()
        print("file created", file_name)


def main():

    parser = argparse.ArgumentParser (
        prog="project-manager", description="project folder structure creation tool")
    parser.add_argument ("-d", "--directory",
                        help="software project folder orgnatation tool",
                        type=str, required=True)
    parser.add_argument ("-g", "--git", action='store_true',
                        help="git auto initialization"
                        )

    args = vars(parser.parse_args())

    with open('setting.json') as f:
        settings = json.load(f)

    for folder in settings["project_folders"]:
        path = args['directory'] + '/' +folder
        try:
            os.makedirs(path)
            print ('folder create -', path)
        except FileExistsError:
            print ('folder exist  -', path)

    for files in settings["project_files"]:
        path = args['directory'] + '/' + files["name"]
        file_create(path, files["text"])

    if (args['git']):
        os.chdir(args['directory'])
        print(" ************* Git creation *************")
        ret = subprocess.call("git init", shell=True)
        git_config = settings["git_config"]
        subprocess.call("git config user.name "+ git_config["name"], shell=True)
        subprocess.call("git config user.email "+ git_config["email"], shell=True)
        ret = subprocess.call("git checkout -b develop", shell=True)
        if ret == 0:
            subprocess.call("git add .", shell=True)
            subprocess.call("git commit -m \"initial commit\" ", shell=True)

    os.chdir(args['directory'])
    
if __name__ == "__main__":
    main ()
