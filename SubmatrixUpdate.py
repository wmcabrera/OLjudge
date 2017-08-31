class NMmatrix(object):
    def __init__(self, N,M):
        self.A=    [ [0]*(M+1) for _ in range(0,N+1)]
    def oper(self,R,C,S,D):
        for i in range(R, R+S):
            ll = range(C,C+S)        
            for j in ll:
            #    print "idx:" ,i,j
                self.A[i][j]+=D
    def printm(self):
        for i in range (1, len(self.A) ):
            ll2 = range(1,len(self.A[1]))
            for j in ll2:
                print self.A[i][j],
            print    
        
values=map(int, raw_input().split())        
N,M,K=values[0],values[1], values[2]
X=NMmatrix(N,M)
for i in range(0,N):
    X.A[i+1]=[0]+map(int, raw_input().split())
for _ in range(0,K):
    optDat= map(int, raw_input().split())
    R,C,S,D= optDat[0],optDat[1],optDat[2],optDat[3]
    X.oper(R,C,S,D)
X.printm()    
