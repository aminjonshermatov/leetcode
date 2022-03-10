import sys
import re
import os
from enum import Enum


class Difficulty(Enum):
    EASY = 'Easy'
    Medium = 'Medium'
    Hard = 'Hard'


class Problem:
    number: int
    title: str
    url: str
    difficulty: Difficulty

    def __str__(self) -> str:
        return f'{{ number: {self.number}, title: {self.title}, url: {self.url}, difficulty: {self.difficulty} }}'


def parse_arguments() -> Problem:
    problem = Problem()
    for argument in sys.argv[1:]:
        match = re.match(r'^--(number|title|url|difficulty)=(.+)$', argument)
        if match is None:
            raise ValueError(f'Invalid format: {argument}')

        attribute, value = match.group(1), match.group(2)
        setattr(problem, attribute, value)
    return problem


def get_file_name(title: str) -> str:
    title = title.translate(title.maketrans(dict.fromkeys(',!.;?', '')))

    def parser(word: str) -> str:
        result = word.title()
        result.replace("'", '')
        return result

    return ''.join(map(parser, title.split(' ')))


def get_readme_str(problem: Problem, file_path: str) -> str:
    return ''.join([
        f'|{problem.number}|',
        f'[{problem.title}]({problem.url})|',
        f'[C++]({file_path})|',
        f'{problem.difficulty}|'
    ])


def generator():
    try:
        problem = parse_arguments()
        file_name = get_file_name(problem.title)
        file_path = f'./algorithms/{file_name}/{file_name}.cpp'

        os.makedirs(os.path.dirname(file_path), exist_ok=True)
        with open(file_path, 'w') as f:
            f.write('#include "bits/stdc++.h"\n\nusing namespace std;\n\n')

        with open('./README.md', 'a') as file:
            readme_str = get_readme_str(problem, file_path)
            file.write(f'{readme_str}\n')
    except ValueError as ex:
        print(ex)


generator()
