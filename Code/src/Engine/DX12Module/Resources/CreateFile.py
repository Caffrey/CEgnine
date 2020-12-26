file_names = {"DX12Utils"}

import os

def new_txt(name):
    a1='实线'
    pwd = os.getcwd() 
    head_path = pwd +"/" + name + ".h"
    cpp_path  =  pwd +"/" + name + ".cpp"
    print(cpp_path)
    head_file = open(head_path, 'w')
    cpp_file = open(cpp_path, 'w')
    head_file.write("#pragma once")
    cpp_file.write("#include \"" + name + ".h\"")

for name in file_names:
	new_txt(name)