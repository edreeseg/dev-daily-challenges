import itertools

# Naive solution

def balance(scaleArr):
    a, b = scaleArr[0]
    weights = scaleArr[1]
    lowest_quantity = None
    a_weight = None
    b_weight = None
    sum_dict = { a: () }
    combo_dict = {}
    for i in range(len(weights)):
        combos = list(itertools.combinations(weights, i))
        combo_dict[i] = combos
        for x in range(len(combos)):
            sum = a
            for n in combos[x]:
                sum += n
            if sum == b:
                lowest_quantity = i
                a_weight = combos[x]
                b_weight = ()
            if sum in sum_dict:
                if x < len(sum_dict[sum]):
                    sum_dict[sum] = combos[x]
            else:
                sum_dict[sum] = combos[x]
    for i in range(len(weights)):
        combos = combo_dict[i]
        for x in range(len(combos)):
            sum = b
            for n in combos[x]:
                sum += n
            if sum in sum_dict:
                current_quantity = i + len(sum_dict[sum])
                if lowest_quantity is None or current_quantity < lowest_quantity:
                    lowest_quantity = current_quantity
                    a_weight = sum_dict[sum]
                    b_weight = combos[x]
    if lowest_quantity is None:
        return 'not possible'
    left = ', '.join(str(n) for n in a_weight) if len(a_weight) else 'nothing'
    right = ', '.join(str(n) for n in b_weight) if len(b_weight) else 'nothing'
    return ('The fewest number of weights needed for equality is '
    f'{lowest_quantity}, putting {left} on the left and {right} on the right.')
