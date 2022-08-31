
import os
from building import *

cwd = GetCurrentDir()
src  = Glob('*.c')

src = Split('''
vofa_plus/src/vofa_plus.c
''')

path = [cwd]
path += [cwd + '/inc']

group = DefineGroup('vofa_plus', src, depend = [''], CPPPATH = path)

Return('group')
