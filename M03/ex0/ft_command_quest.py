import sys

number_arguments = len(sys.orig_argv)
i = 1
while i <= number_arguments:
    print(f"Argument {i}:", sys.argv[i])
    i += 1
print("Total arguments:", number_arguments)
