brackets = '(][1243uy81nb1][d2d22d231  12 e)'
all(brackets.count(opening) == brackets.count(closing) for opening, closing in zip("[({", "])}"))
# https://python-scripts.com/question/3488  (Check for correct number of brackets)
