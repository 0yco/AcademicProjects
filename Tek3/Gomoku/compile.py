import os
from os import system

source_dir = "src/"
files = [os.path.join(root, file) for root, dirs, files in os.walk(source_dir) for file in files]

files_list = " ".join(files)

system("pip install pyinstaller")
system(f"pyinstaller {files_list} --name pbrain-gomoku-ai.exe --onefile")
system('copy .\\dist\\pbrain-gomoku-ai.exe .')