project('LearningObjectiveGenerator', 'c',
  version : '1.0.0',
  default_options : ['warning_level=3'])

files = [
  'src/learningobjectivegenerator.c',
  'src/objective-options.c',
]

exe = executable('learningobjectivegenerator', files,
  install : true)

testArgs = [
  '-level',
  '1',
  '-grade',
  '1',
  '-subject',
  'art',
  '-domain-level',
  '0'
]

test('basic', exe, args: testArgs)
