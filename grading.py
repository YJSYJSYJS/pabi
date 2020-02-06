math = input("Math score: ")
eng = input("English score: ")

math = float(math)
eng = float(eng)

avg = (math+eng)/2
print("Average score: ", avg)

if avg>=90:
    grade = 'A'
elif avg>=80:
    grade = 'B'
elif avg>=70:
    grade = 'C'
elif avg>=60:
    grade='D'
else:
    grade='F'

print("Grade: ", grade)