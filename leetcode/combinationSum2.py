from collections import Counter


def combinationSum2(candidates, target: int):

    def backtrack(comb, remain, curr, counter, results):
        if remain == 0:
            # make a deep copy of the current combination
            #   rather than keeping the reference.
            results.append(list(comb))
            return
        elif remain < 0:
            return

        for next_curr in range(curr, len(counter)):
            candidate, freq = counter[next_curr]

            if freq <= 0:
                continue

            # add a new element to the current combination
            comb.append(candidate)
            counter[next_curr] = (candidate, freq-1)

            # continue the exploration with the updated combination
            backtrack(comb, remain - candidate, next_curr, counter, results)

            # backtrack the changes, so that we can try another candidate
            counter[next_curr] = (candidate, freq)
            comb.pop()

    results = []  # container to hold the final combinations
    counter = Counter(candidates)
    # convert the counter table to a list of (num, count) tuples
    counter = [(c, counter[c]) for c in counter]

    backtrack(comb = [], remain = target, curr = 0,
                counter = counter, results = results)

    return results

candidates = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
target = 30

res = combinationSum2(candidates, target)
print(res)