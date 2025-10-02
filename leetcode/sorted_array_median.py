
def easy(nums1, nums2):
    def median(ls):
        if len(ls) % 2 == 0:
            return (ls[len(ls) // 2] + ls[len(ls) // 2 - 1]) / 2

        else:
            return ls[len(ls) // 2]

    return median(sorted(nums1 + nums2))


def pointer_solution(nums1: list[int], nums2: list[int]):
    mer_len = len(nums1) + len(nums2)

    mer_idx = 0

    idx_1 = 0
    idx_2 = 0

    elem = -1

    middle_sum = 0

    while mer_idx < mer_len:
        if idx_1 == len(nums1):
            elem = nums2[idx_2]
            mer_idx += 1
            idx_2 += 1

        elif idx_2 == len(nums2):
            elem = nums1[idx_1]
            mer_idx += 1
            idx_1 += 1

        elif nums1[idx_1] <= nums2[idx_2]:
            elem = nums1[idx_1]
            mer_idx += 1
            idx_1 += 1

        else:
            elem = nums2[idx_2]
            mer_idx += 1
            idx_2 += 1

        if mer_len % 2 == 0:
            if mer_idx - 1 in {mer_len // 2, mer_len // 2 - 1}:
                middle_sum += elem
        elif mer_idx - 1 == mer_len // 2:
            return elem

    return middle_sum / 2


def main():
    solution = pointer_solution

    nums1 = [1,3]
    nums2 = [2]

    result = solution(nums1, nums2)
    print(result)

    nums1 = [1,2]
    nums2 = [3,4]

    result = solution(nums1, nums2)
    print(result)


if __name__ == "__main__":
    main()
