import collections 

class Sol:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = collections.defaultdict(set)
        rows = collections.defaultdict(set)
        squares = collections.defaultdict(set)


        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if(board[r][c] in rows[r] or
                   board[r][c] in cols[r] or
                   board[r][c] in squares[(r//3, c//3)] ):
                    return False
                
                cols[c].add(board[r][c])
                rows[c].add(board[r][c])
                squares[c].add(board[r][c])
        return True
                
