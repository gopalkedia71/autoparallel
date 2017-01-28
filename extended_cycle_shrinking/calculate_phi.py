def test_calculate_phi():
    m = 2
    indices = ['i','j']
    num_ref = 4
    ref_index = ['i','j','i','j']
    ref_index_coeff = [1,1,1,1]
    ref_left_const = [4,-6,3,-4]
    ref_right_const = [0,0,0,0]
    phi = [None]*m
    phi = calculate_phi(m,indices,num_ref,ref_index,ref_index_coeff,ref_left_const,ref_right_const,phi)
    assert phi == [3,-4]

def calculate_phi(m,indices,num_ref,ref_index,ref_index_coeff,ref_left_const,ref_right_const,phi):
    for i in range(num_ref):
        for j in range(m):
            if ref_index[i] == indices[j]:
                if phi[j] == None:
                    phi[j] = (ref_left_const[i]-ref_right_const[i])/ref_index_coeff[i]
                else:
                    if (phi[j]*ref_index_coeff[i])/(ref_left_const[i]-ref_right_const[i]) <= 0:
                        phi[j] = 0
                    else:
                        if phi[j]>0:
                            phi[j] = min((phi[j]),((ref_left_const[i]-ref_right_const[i])/ref_index_coeff[i]))
                        else:
                            phi[j] = -min(abs(phi[j]),abs((ref_left_const[i]-ref_right_const[i])/ref_index_coeff[i]))
    return phi

if __name__ == "__main__" :
    test_calculate_phi()
