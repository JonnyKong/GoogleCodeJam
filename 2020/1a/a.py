def solve(strs):
    # print(strs)
    possible, ret = has_fixed_sol(strs)
    if not possible:
        return '*'
    if ret:
        return ret

    possible, prefix = get_valid_prefix(strs)
    if not possible:
        return '*'
    # print('Valid prefix:', prefix)

    possible, suffix = get_valid_suffix(strs)
    if not possible:
        return '*'
    # print('Valid suffix:', suffix)

    ret = ""
    for str in strs:
        str_splitted = str.split('*')
        if len(str_splitted) <= 2:
            continue
        ret += "".join(str_splitted[1:-1])
    if prefix:
        ret = prefix + ret
    if suffix:
        ret = ret + suffix
    return ret
    
# return (t/f, valid_prefix)
def get_valid_prefix(strs):
    prefix = None
    # get longest prefix
    for str in strs:
        str_splitted = str.split('*')
        while("" in str_splitted): 
            str_splitted.remove("")
        if str[0] == '*':
            continue
        elif prefix == None:
            prefix = str_splitted[0]
        elif len(str_splitted[0]) > len(prefix):
            prefix = str_splitted[0]
    # check if valid
    for str in strs:
        str_splitted = str.split('*')
        while("" in str_splitted) : 
            str_splitted.remove("")  
        if str[0] == '*':
            continue
        elif not prefix.startswith(str_splitted[0]):
            return (False, None)
    return (True, prefix)
        
# return (t/f, valid_prefix)
def get_valid_suffix(strs):
    suffix = None
    # get longest suffix
    for str in strs:
        str_splitted = str.split('*')
        while("" in str_splitted): 
            str_splitted.remove("")  
        if str[-1] == '*':
            continue
        elif suffix == None:
            suffix = str_splitted[-1]
        elif len(str_splitted[-1]) > len(suffix):
            suffix = str_splitted[-1]
    # check if valid
    for str in strs:
        str_splitted = str.split('*')
        while("" in str_splitted) : 
            str_splitted.remove("")  
        if str[-1] == '*':
            continue
        elif not suffix.endswith(str_splitted[-1]):
            return (False, None)
    return (True, suffix)  

# Return (t/f, fixed_sol)
def has_fixed_sol(strs):
    maybe_sol = None
    for str in strs:
        if '*' not in str:
            maybe_sol = str
    if maybe_sol:
        for str in strs:
            if not (str[0] == '*' or maybe_sol.startswith(str.split('*')[0])):
                return (False, None)
            elif not(str[-1] == '*' or maybe_sol.endswith(str.split('*')[-1])):
                return (False, None)

    return (True, maybe_sol)
                


if __name__ == '__main__':
    t = int(input())
    for z in range(t):
        n = int(input())
        strs = []
        for i in range(n):
            s = str(input()).strip()
            strs.append(s)
        ret = solve(strs)
        print('Case #{}: {}'.format(z + 1, ret))