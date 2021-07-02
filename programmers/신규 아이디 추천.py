import re
def solution(new_id):
    remove_char = '~!@#$%^&*()=+[{]}:?,<>/' # 정의
    new_id = new_id.lower() # 1단계
    for char in new_id: # 2단계
        if char in remove_char:
            new_id = new_id.replace(char, '')

    new_id = re.sub(r'\.{2,}', '.', new_id) # 3단계

    if new_id[0] == '.':
        if len(new_id) == 1:
            new_id = new_id.replace('.', '')
        else:
            new_id = new_id[1:]
    elif new_id[-1] == '.': # 4단계
        if len(new_id) == 1:
            new_id = new_id.replace('.', '')
        else:
            new_id = new_id[:-1]
    
    if len(new_id) == 0: # 5단계
        new_id = 'a'
        
    if len(new_id) >= 16: # 6단계
        new_id = new_id[:15]
    if new_id[-1] == '.':
        new_id = new_id[:-1]
    
    if len(new_id) <= 2:
        while len(new_id) < 3:
            new_id += new_id[-1]
    
    return new_id
