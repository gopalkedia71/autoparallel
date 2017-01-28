""" Extended cycle shrinking algorithm finds the dependence distance vector phi(L) based on the below phenomenon

    phi_k(L) = 0 if there exists some reference pair R for which phi_k(R) = 0 there exist two reference pair R and R' such that phi_k(R) and phi_k(R') have opposite signs
             = min (phi_k(R)) if sign(phi_k(R)) is positive for all R,and
             = -min(|phi_k(R)|) if sign(phi_k(R)) is negative for all R."""

""" INPUT: A m-nested loop with its indices and bounds. Number of reference pairs along with each pairs index and their coefficients and their constants in both source and sink """
import math
import calculate_phi

if __name__ == '__main__' :
    m = int(input(""))
    indices = []
    for i in range(m):
        indices.append(input(""))
    bound = []
    for i in range(2*m):
        bound.append(int(input("")))
    num_ref = int(input(""))
    ref_index = [None]*num_ref
    ref_index_coeff = [None]*num_ref
    ref_left_const = [None]*num_ref
    ref_right_const = [None]*num_ref
    for i in range(num_ref):
        ref_index[i] = (input(""))
        ref_index_coeff[i] = int(input(""))
        ref_left_const[i] = int(input(""))
        ref_right_const[i] = int(input(""))
    phi = [None]*m
    phi = calculate_phi.calculate_phi(m,indices,num_ref,ref_index,ref_index_coeff,ref_left_const,ref_right_const,phi)

    """ METHOD: Number of groups = 1 to min(N_i/phi_i) """

    length = []
    for i in range(m):
        length.append(bound[2*i + 1] - bound[2*i] + 1)
        if i == 0:
            num_groups = math.ceil(length[0]/abs(phi[0]))
        else:
            num_groups = min(num_groups , math.ceil(length[i]/abs(phi[i])))

    """ The output is generated here """

    print("for(int k = 1; k<=%s ; k++)" % num_groups)

    print("{")

    print("    for(int i = 1; i<=%s; i++)" % m)

    print("    {")

    print("        if phi[i] >= 0")

    print("            {")

    print("            }")

    print("    }")

    print("}")
