
def find_swap(next, sorted_tail):
    """
    return negative int index in sorted tail of thing to swap
    """
    if len(sorted_tail) == 1:
        return -1
    i = -2
    while abs(i) <= len(sorted_tail):
        if next > sorted_tail[i]:
            return i+1
        i -= 1


def do_swap(head, sorted_tail, swap_neg_index):
    """return list final answer"""
        
    assert(len(sorted_tail) >= abs(swap_neg_index))
    
    temp = head[-1]
    head[-1] = sorted_tail[swap_neg_index]
    sorted_tail[swap_neg_index] = temp
    
    assert(len(head)>0)
    assert(len(sorted_tail)>0)
    return head + sorted_tail

    
def bigger_is_greater(word):
    sorted_tail = [word[-1]]
    
    for i in range(len(word)-2,-1,-1):
        next = word[i]

        if next < sorted_tail[-1]:
            swap_neg_index = find_swap(next, sorted_tail)
            return ''.join(do_swap(word[:i+1], sorted_tail, swap_neg_index))
        sorted_tail.append(next)
    
    return "no answer"
            


num_lines = int(input().strip())
for l in range(num_lines):
    word_as_list = list(input().strip())
    print(bigger_is_greater(word_as_list))
