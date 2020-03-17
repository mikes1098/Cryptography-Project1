import random

SPLIT_LEN_RAND = 10

ENGLISH_DICT_FILE = "english_words.txt"

DICT_AVG_FREQ = {' ': 19, 'a': 7, 'b': 1, 'c': 2, 'd': 4, 'e': 10, 
              'f': 2,'g': 2, 'h': 5, 'i': 6,'j': 1, 'k': 1, 'l': 3,
              'm': 2, 'n': 6, 'o': 6,'p': 2, 'q': 1, 'r': 5,'s': 5, 
              't': 7, 'u': 2,'v': 1, 'w': 2, 'x': 1, 'y': 2, 'z': 1}

DICT_KEYS = {' ': [], 'a': [], 'b': [], 'c': [], 'd': [], 'e': [], 'f': [],'g': [],
              'h': [], 'i': [],'j': [], 'k': [], 'l': [],'m': [], 'n': [],
              'o': [],'p': [], 'q': [], 'r': [],'s': [], 't': [],
              'u': [],'v': [], 'w': [], 'x': [], 'y': [], 'z': []}

def random_sublist(input_list):
    res_list = []
    index = 0
    end = 0

    if len(input_list) > SPLIT_LEN_RAND:
        end = SPLIT_LEN_RAND
    else:
        end = len(input_list)

    while index < len(input_list):
        r_num = random.randint(1, end)
        res_list.append(input_list[index:index+r_num])
        index = index + r_num

    return res_list

def get_dict_list(r_dict):
    temp_dic = DICT_KEYS
    for key, value in r_dict.items():
        temp_dic[value].append(key)
    return temp_dic

def process_res(inpt_cipher_txt):
    outer = 0
    inner = 0

    chk1 = True
    chk2 = True

    dict_keys_cpy = DICT_KEYS
    km_dict = {}
    o_list = {}
    r_dict = {}
    
    new_num_list = []
    temp_list = []
    container_tmp_list = []
    v_f = []

    if len(inpt_cipher_txt) not in o_list:
        with open(ENGLISH_DICT_FILE, "r") as ins:
            array = []
            for line in ins:
                array.append(line)

            for word in array:
                
                if len(word) == len(inpt_cipher_txt):
                    print(word)
                    temp_list.append(word.rstrip())
        o_list[len(inpt_cipher_txt)] = random.sample(temp_list, len(temp_list))

    while outer < len(inpt_cipher_txt):
        if outer not in v_f:
            if len(container_tmp_list) > outer:
                del container_tmp_list[outer:]
            mp_list = o_list[len(inpt_cipher_txt)]
            container_tmp_list.append(mp_list)
            v_f.append(outer)

        while len(container_tmp_list[outer]) > 0:
            while inner < len(inpt_cipher_txt)-1:
                cmp_elem = container_tmp_list[outer][0][inner]
                if inpt_cipher_txt[inner] in r_dict:
                    if r_dict[inpt_cipher_txt[inner]] != cmp_elem:
                        for key in new_num_list:
                            del r_dict[key]
                        dict_keys_cpy = {}
                        dict_keys_cpy = get_dict_list(r_dict)
                        new_num_list = []
                        chk1 = False
                        break
                else:
                    if len(dict_keys_cpy[cmp_elem]) == DICT_AVG_FREQ[cmp_elem]:

                        for key in new_num_list:
                            del r_dict[key]

                        dict_keys_cpy = get_dict_list(r_dict)
                        new_num_list = []
                        chk1 = False
                        break

                    dict_keys_cpy[cmp_elem].append(inpt_cipher_txt[inner])
                    r_dict[inpt_cipher_txt[inner]] = cmp_elem
                    new_num_list.append(inpt_cipher_txt[inner])

                inner = inner+1

            if chk1:
                chk2 = True
                km_dict[outer] = new_num_list
                new_num_list = []
                inner = 0
                break
            else:
                chk2 = False
                inner = 0
                del container_tmp_list[outer][0]

        if chk2:
            outer = outer+1
        else:
            chk2 = True
            if outer == 0:
                return []

            for key in new_num_list:
                del r_dict[key]

            new_num_list = []

            v_f.remove(outer)
            outer = outer-1

            for key in km_dict[outer]:
                del r_dict[key]
            dict_keys_cpy = get_dict_list(r_dict)
            del km_dict[outer]
            del container_tmp_list[outer][0]

    return r_dict

def main():
    res_str = ""

    while True:
        print ("Enter Path To Comma-Separated CipherText File: ")
        filename = input("")

        cipher_num = ""
        cipher_list = []
        with open(filename) as f:
            while True:
                c = f.read(1)
                if not c:
                    print ("End of file")
                    cipher_list.append(int(cipher_num))
                    break
                if c == ",":
                    cipher_list.append(int(cipher_num))
                    cipher_num = ""
                else:
                    cipher_num += c

        container_cipher =  []
        container_cipher.append(cipher_list)
        if len(cipher_list) == 0:
            print("Error with input format, please try again.")
        else:
            break 

    all_ciphers = random_sublist(cipher_list)

    res_plaintext = [] 
    print(all_ciphers)
    for c_list in all_ciphers:
        res_arr = process_res(c_list)

        if len(res_arr) == 0:
            print ("Unable to get exact matches.")
        else:
            print(c_list)
            l = len(c_list)
            z = 0
            for item in c_list:
                z += 1

                if z == l:
                    break
                res_str += res_arr[item]

            res_str += ' '
            res_plaintext.append(res_str)

    print(res_plaintext)

    if len(res_plaintext) > 0:
        print("Plaintext guess: " + res_plaintext[-1])
    else:
        print("Sorry, no plaintext match found.")

if __name__ == "__main__":
    main()