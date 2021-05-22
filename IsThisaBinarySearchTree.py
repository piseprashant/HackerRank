def check_binary_search_tree_(root):
    
    def check(root, min_Value, max_value):
        
        # base case
        if root is None:
            return True
        
        if root.data < min_Value or root.data > max_value:
            return False
        
        return check(root.left, min_Value, root.data -1) and check(root.right, root.data+1, max_value)
        
    return check(root, 0, 10000)
