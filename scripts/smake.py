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


import argparse, uuid
from os import path
from datetime import date

year = str(date.today().year)
copyright_tmpl = \
"""/**\cond
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) """ + year + """ Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  \endcond*/
"""

header_incl_tmpl = \
"""
#ifndef %(filename)s_%(uuid)s
#define %(filename)s_%(uuid)s

#ifdef __cplusplus
 extern "C" {
#endif

#define __%(filename)s_VERSION      (0x0001u)




#ifdef __cplusplus
}
#endif

#endif /* %(filename)s_%(uuid)s */
"""

config_incl_tmpl = \
"""
#ifndef %(filename)s_%(uuid)s
#define %(filename)s_%(uuid)s

#ifdef __cplusplus
 extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#endif /* %(filename)s_%(uuid)s */
"""

def h_create (file_handle, fname):
    file_handle.write (copyright_tmpl)
    file_handle.write (header_incl_tmpl %
                       ({'uuid': str(uuid.uuid1()).replace('-','_'),
                         'filename': str(fname).upper().replace('-','_')}),)
    file_handle.close ()

def cfg_create (file_handle, fname):
    file_handle.write (copyright_tmpl)
    file_handle.write (config_incl_tmpl %
                       ({'uuid': str(uuid.uuid1()).replace('-','_'),
                         'filename': str(fname).upper().replace('-','_')}),)
    file_handle.close ()

def src_create (file_handle):
    file_handle.write (copyright_tmpl)
    file_handle.close ()

def main():
    parser = argparse.ArgumentParser (
        prog="smake", description="C/C++ source and header file generation tool")
    parser.add_argument ("-f", "--file-name",
                         help="C/C++ header/source file name",
                         type=str, required=True)

    parser.add_argument ("-d", "--directory",
                         help="C/C++ header/source create directory",
                         type=str, required=False)

    parser.add_argument ("-s", "--smart",
                         help="C/C++ header/source create in source and config",
                         type=str, required=False)

    args = vars(parser.parse_args ())

    if args['directory'] is not None:
        path_src = args['directory'] + '/' + args['file_name']
        path_cfg = path_src
    elif args['smart'] is not None:
        path_src = args['smart'] + '/' + 'source' + '/' + args['file_name']
        path_cfg = args['smart'] + '/' + 'config' + '/' + args['file_name']
    else:
        path_src = args['file_name']
        path_cfg = path_src

    src_path = (path_src+'.c')
    
    if(path.exists(src_path)):
        print("file exists", src_path)
    else:
        c_file = open(src_path,'w')
        src_create(c_file)
        print("file create", src_path)

    src_path = (path_src+'.h')

    if(path.exists(src_path)):
        print("file exists", src_path)
    else:
        h_file = open(src_path,'w')
        h_create(h_file, args['file_name'])
        print("file create", src_path)

    src_path = (path_cfg + '-cfg.h')

    if(path.exists(src_path)):
        print("file exists", src_path)
    else:
        cfg_file = open(src_path,'w')
        cfg_create(cfg_file, args['file_name'])
        print("file create", src_path)
    

if __name__ == "__main__":
    main ()