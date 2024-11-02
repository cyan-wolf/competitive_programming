
class Node:
    def __init__(self, left, value, right):
        self.left = left
        self.value = value
        self.right = right

def add_elem(bst, elem, letter_weight):
    if bst is None:
        return Node(None, elem, None)
    
    else:
        if letter_weight[elem] < letter_weight[bst.value]:
            bst.left = add_elem(bst.left, elem, letter_weight)

        elif letter_weight[elem] > letter_weight[bst.value]:
            bst.right = add_elem(bst.right, elem, letter_weight)

        return bst

def to_tree(word):
    letter_weight = {}
    for c in word:
        letter_weight.setdefault(c, 0)
        letter_weight[c] += ord(c)

    letters = list(word)

    # TODO: I need to rotate the tree.
    root = max(letters, key=lambda c: letter_weight[c])
    tree = add_elem(None, root, None)

    for elem in letters:
        if elem != root:
            tree = add_elem(tree, elem, letter_weight)

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


