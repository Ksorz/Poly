# Lists           Списки    [] Square brackets is a list constant. (lists are -- mutable --)
# Dictionaries    Словари   {} Curly braces is a dictionary constant. (dictionaries are -- mutable --)
# Tuples          Кортежи   () Parenthesis is a tuples constant. (tuples are -- immutable --)
# Strings are -- immutable -- we must make a new string to make any change

True; False; None; 5; 170; 'W'; 'p' # CONSTANTs
def FunctionName(parameter_1, parameter_2): # parameter_1, parameter_2 is an alias(name) of function`s PARAMETERs
    some function`s code # STATEMENT 'def' defines FUNCTION FunctionName

2 != 3 # OPERATORs != + == etc
something[x] # OPERATOR [] index (we pronounce it as SUB, "something sub x")
3 is 3.0 # OPERATOR 'is' means "is it exacly the same? (type and value)" 'is' more powerful than '==' 3 == 3.0 (True)
'thing' in 'something' # OPERATOR 'in' checks is 'thing' contains inside 'something' or not

while True: # LOOP indeterminate
    some code
for i in j:# LOOP determinate
    some code

quit() # FUNCTION 'quit' stop`s the program
input('Message:') # FUNCTION 'input' shows you a "Message:" and waits until you enter something, than return`s it
type(something) #
max(something) # FUNCTION 'max' that return`s max value of something ARGUMENT inside parenthesis
min(something) # FUNCTION 'max' that return`s min value of something ARGUMENT inside parenthesis
len(list_string_array) # FUNCTION 'len' gives us a length of a ARGUMENT list, string, array
ord('s') # Numeric value of a simple ASCII caracter
round(float number) # Number rounding (float -> int)
break # STATEMENT 'break' skips OUT of the loop
continue # STATEMENT 'continue' skips to the TOP (abandons the current and goes to the next iteration) of the loop

x = 'Monty\nPython' # \n is SPECIAL CARACTER called 'newline'
print(x[:5]) # Monty
print(x[6:]) # Python
print(x[:]) # Monty Python
print(x[0:1]) # M
print(x[0:99]) # Monty Python
print(x[99]) # Traceback!
type(x) # FUNCTION 'type' returns us the class of ARGUMENT
dir(x) # FUNCTION 'dir' returns us what ARGUMENT.METHODs() we can do with the class of 'ARGUMENT' belongs to
# --      https://docs.python.org/3/                 -- Original documentation
# --      https://pythoner.name/documentation        -- Russian documentation
# Common METHODS:
str.capitalize() # Return a copy of the string with its first character capitalized and the rest lowercased.
str.find(sub[, start[, end]]) # Return the lowest index in the string where substring sub is found within the slice s[start:end]. Optional arguments start and end are interpreted as in slice notation. Return -1 if sub is not found.
str.lower() # Return a copy of the string converted to lowercase.
str.upper() # Return a copy of the string converted to uppercase.
str.replace(old, new[, count]) # Return a copy of the string with all occurrences of substring old replaced by new. If the optional argument count is given, only the first count occurrences are replaced.
str.strip([chars])  # Return a copy of the string with leading and trailing characters removed. Chars same as 'rstrip'
str.lstrip([chars]) # Return a copy of the string with leading characters removed. The chars argument same as 'rstrip'
str.rstrip([chars]) # Return a copy of the string with trailing characters removed. The chars argument is a string specifying the set of characters to be removed. If omitted or None, the chars argument defaults to removing whitespace. The chars argument is not a suffix; rather, all combinations of its values are stripped:
>>> '   spacious   '.rstrip()   #'   spacious'
>>> 'mississippi'.rstrip('ipz') # 'mississ'
str.startswith(prefix[, start[, end]]) # Return True if string starts with the prefix, otherwise return False. prefix can also be a tuple of prefixes to look for. With optional start, test string beginning at that position. With optional end, stop comparing string at that position.
str.center(width[, fillchar]) # Return centered in a string of length width. Padding is done using the specified fillchar (default is an ASCII space). The original string is returned if width is less than or equal to len(s).
str.endswith(suffix[, start[, end]]) # Return True if the string ends with the specified suffix, otherwise return False. suffix can also be a tuple of suffixes to look for. With optional start, test beginning at that position. With optional end, stop comparing at that position.
array.append(x) # Append a new item with value x to the end of the array.
array.insert(i, x) # Insert a new item with value x in the array before position i. Negative values are treated as being relative to the end of the array.
str.split(sep=None, maxsplit=-1) # Return a list of the words in the string, using sep as the delimiter string.
# for more inf ^^^^^ https://docs.python.org/3/library/stdtypes.html?highlight=split#str.split
dict.get(key[, default]) # Return the value for key if key is in the dictionary, else default. If default is not given, it defaults to None, so that this method never raises a KeyError.

















































____
