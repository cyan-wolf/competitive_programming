ELEMENTS = """H
He
Li
Be
B
C
N
O
F
Ne
Na
Mg
Al
Si
P
S
Cl
Ar
K
Ca
Sc
Ti
V
Cr
Mn
Fe
Co
Ni
Cu
Zn
Ga
Ge
As
Se
Br
Kr
Rb
Sr
Y
Zr
Nb
Mo
Tc
Ru
Rh
Pd
Ag
Cd
In
Sn
Sb
Te
I
Xe
Cs
Ba
La
Ce
Pr
Nd
Pm
Sm
Eu
Gd
Tb
Dy
Ho
Er
Tm
Yb
Lu
Hf
Ta
W
Re
Os
Ir
Pt
Au
Hg
Tl
Pb
Bi
Po
At
Rn
Fr
Ra
Ac
Th
Pa
U
Np
Pu
Am
Cm
Bk
Cf
Es
Fm
Md
No
Lr
Rf
Db
Sg
Bh
Hs
Mt
Ds
Rg
Cn
Nh
Fl
Mc
Lv
Ts
Og
"""

# ACCEPTED

def print_chemical_sentence_format(letters, table1, table2):
    stk = list(letters[::-1])
    symbols = []

    def find_elem_seq(acc, stk, seq):
        if len(acc) == 0 and len(stk) == 0:
            # Found solution.
            # NOTE: This keeps reseting the `symbols` array
            # because the problem only accepts the most recently 
            # found solution, not necessarily all valid ones.
            symbols.clear()
            symbols.extend(seq)

        elif len(acc) == 0 and len(stk) > 0:
            # Check with 1 letter.
            acc = stk[-1].lower()
            find_elem_seq(acc, stk[:-1], seq)

            if len(stk) > 1:
                # Check with 2 letters.
                acc = (stk[-1] + stk[-2]).lower()
                find_elem_seq(acc, stk[:-2], seq)

        # Check if the current accumulator is an element, 
        # if so add it to the sequence.
        elif acc in table1:
            seq = seq.copy()
            seq.append(acc)
            find_elem_seq("", stk, seq)

    # Start the recursion.
    find_elem_seq("", stk, [])

    if len(symbols) == 0:
        print("-- Could not be formed.")
        return
    
    atomic_nums = [table1[symm][1] for symm in symbols]
    proper_symbols = [table1[symm][0] for symm in symbols]

    avg_num = round(sum(atomic_nums) / len(atomic_nums))
    avg_elem_sym = table2[avg_num]

    print(" ".join(proper_symbols))
    print(f"Average Atomic Number: {avg_num} Element is: {avg_elem_sym}")

def read_elements():
    # table1: symbol -> (presentatble symbol, atomic number)
    # table2: atomic number -> presentable symbol
    table1, table2 = {}, {}
    
    atomic_number = 1

    for symbol in ELEMENTS.split():
        table1[symbol.lower()] = (symbol, atomic_number)
        
        table2[atomic_number] = symbol

        atomic_number += 1 

    return table1, table2

def main():
    # Remove the spaces between words.
    letters = input().split()
    # Remove the final period.
    letters[-1] = letters[-1][:-1]
    # Join the letters into one string.
    letters = "".join(letters)

    table1, table2 = read_elements()

    print_chemical_sentence_format(letters, table1, table2)

if __name__ == "__main__":
    main()

