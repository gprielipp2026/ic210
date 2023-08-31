import subprocess

tests = [ "12:00AM", "12:00PM", "3:00AM", "3:30PM", "10:59PM", "11:59PM" ]
expec = [ "00:00"  , "12:00"  , "03:00" , "15:30" , "22:59"  , "23:59"]
for test, actual in zip(tests, expec):
    result = subprocess.run(["./time"], capture_output=True, text=True, input=f"{test}")
    print(f'{test} => {result.stdout[-6:-1:]}')
    assert result.stdout[-6:-1:] == actual