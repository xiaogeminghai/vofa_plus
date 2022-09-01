
import os
from building import *

cwd = GetCurrentDir()

src = Split('''
vofa_plus/src/vofa_plus.c
''')
path = [cwd + '/vofa_plus/inc']

group = DefineGroup('vofa_plus', src, depend = ['PKG_USING_VOFA_PLUS'], CPPPATH = path)

Return('group')
