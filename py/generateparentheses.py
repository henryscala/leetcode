#problem 22 of leetcode
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        states = [] 
        state=[]
        states.append(state)

        i=0 
        while i<2*n:
            newStates=[]
            for state in states:
                extended_list = self.extend_state(state,i,n)
                if extended_list:
                    for e in extended_list:
                        newStates.append(e)
            states = newStates            
            i += 1            
        states=[state for state in states if sum(state) == 0]

        
        result = [self.state_to_str(state) for state in states]
        return result

    def state_to_str (self,state):
        num2char = {1:'(',-1:')'}
        chars = [num2char[i] for i in state]
        return "".join(chars)
    
    #state: List[int]
    #1 means left paren
    #-1 means right paren
    #return List[List[int]]
    def extend_state(self,state,i,n):
        
        result = []
        currsum = sum(state)
        if currsum<n: #accept left paren
            newState=state[:]
            newState.append(1)#left paren
            result.append(newState)

        if currsum>0: #accept right paren
            newState=state[:]
            newState.append(-1)
            result.append(newState)
            
        return result

    def test(self):
        result=self.generateParenthesis(3)
        for i in result:
            print(i,end=", ")
        print()    
        
