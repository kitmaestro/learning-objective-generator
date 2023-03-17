project('LearningObjectiveGenerator', 'c',
  version : '1.0.0',
  default_options : ['warning_level=3'])

files = [
  'src/learningobjectivegenerator.c',
  'src/lib/objective-options.c',
  'src/lib/utils.c',
  'src/generators/art-generator.c',
  'src/generators/english-generator.c',
  'src/generators/spanish-generator.c',
]

exe = executable('learningobjectivegenerator', files,
  install : true)

testArgs = [
  '-l',
  '1',
  '-g',
  '1',
  '-s',
  'a',
  '-d',
  '1',
  'Los numeros romanos'
]

test('basic', exe, args: testArgs)
