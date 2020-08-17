project('basic80', 'c', version: '0.1',
  default_options: [
      'c_std=c99',
     'warning_level=3'
    ]
)

add_project_arguments(
  '-pedantic',
  language: 'c'
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required: true)

basic80 = executable('basic',
  'main.c',
  'command.c',
  'error.c',
  'file.c',
  'math.c',
  'program.c',
  'var.c',
  install: true,
  dependencies: m_dep
)

# vim:set ts=2 sw=2 et:
