def solution(s):
    answer = len(s)
    
    for i in range(1, (len(s)//2)+1):
        compress = ''
        cnt = 1
        temp = s[0:i]
        
        for j in range(i, len(s), i):
            if temp == s[j:j+i]:
                cnt += 1
            else :
                if cnt > 1:
                    compress += str(cnt)
                compress += temp
                temp = s[j:j+i]
                cnt = 1
        if cnt > 1: 
            compress += str(cnt)
        compress += temp
        answer = min(answer, len(compress))
        
    return answer
