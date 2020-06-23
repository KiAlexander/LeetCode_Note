import os
import re

file_dir = '.'
file_name = './README.md'

first_dir = os.listdir(file_dir)
first_dir.remove('.git')
first_dir.remove('README.md')
first_dir.remove('question_number.py')

second_dir = []
for f in first_dir:
	ss = os.listdir(os.path.join(file_dir,f))
	for s in ss:
		second_dir.append((s,re.findall(r"\d+",s)[0]))

def takeSecond(elem):
	return elem[1]

second_dir = list(set(second_dir))
second_dir.sort(key=takeSecond)
print(second_dir)

with open(file_name, 'w', encoding = 'utf-8') as f:
	f.writelines('# LeetCode_Note\n')
	f.writelines('leetcode personal note\n\n')
	f.writelines('# Question List\n')
	for s in second_dir:
			f.writelines('* [x] ['+s[0]+']\n')

print('done!')
