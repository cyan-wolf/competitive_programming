
# FAILED

class Node:
    def __init__(self, left, value, right):
        self.left = left
        self.value = value
        self.right = right

    def __str__(self):
        return f"Node({self.value}, {self.left}, {self.right})"

def add_elem(bst, elem, letter_weight):
    if bst is None:
        return Node(None, elem, None)
    
    else:
        if letter_weight[elem] < letter_weight[bst.value]:
            bst.left = add_elem(bst.left, elem, letter_weight)

        elif letter_weight[elem] > letter_weight[bst.value]:
            bst.right = add_elem(bst.right, elem, letter_weight)

        return bst
    
# This code does not work (?).
def rotate_left(tree):
    old_root = tree
    new_root = tree.right
    old_left = new_root.left

    new_root.left = old_root
    old_root.right = old_left

    return new_root

def to_tree(word):
    letter_weight = {}
    for c in word:
        letter_weight.setdefault(c, 0)
        letter_weight[c] += ord(c)

    letters = list(word)

    tree = None
    for elem in letters:
        tree = add_elem(tree, elem, letter_weight)

    # Set the "heaviest" letter to root.
    while tree.right != None:
        tree = rotate_left(tree)

    return tree

def append_postorder(tree, acc):
    if tree is not None:
        append_postorder(tree.left, acc)
        append_postorder(tree.right, acc)
        acc.append(tree.value)

def main():
    word = input()
    tree = to_tree(word)

    output = []
    append_postorder(tree, output)
    print("".join(output))

if __name__ == "__main__":
    main()


