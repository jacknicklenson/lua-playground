project('lua-playground', 'c',
        default_options: ['default_library=static', 'c_std=c99', 'warning_level=3', 'werror=true'])

cc = meson.get_compiler('c')
if cc.get_id() == 'msvc'
  add_global_arguments('/D_CRT_SECURE_NO_WARNINGS', language : 'c')
endif

m_dep = cc.find_library('m', required : false)
m_lua = dependency('lua')

source_files = [
  'src/main.c'
]

executable('lua-playground', sources: source_files,
           include_directories: include_directories(['src']),
           dependencies: [m_dep, m_lua])
