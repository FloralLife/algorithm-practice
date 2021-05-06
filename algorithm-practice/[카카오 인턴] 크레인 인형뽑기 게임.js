function solution(board, moves) {
    var answer = 0;
    let dolls = [];

    for(let i = 0; i < board.length; i++){
        let doll = [];
        for(let j = board.length - 1; j >= 0; j--){
            if (board[j][i] === 0) break;
            doll.push(board[j][i]);
        }
        dolls.push(doll);
    }
    let basket = [];
    for(let i of moves){
		i--;
        if (dolls[i].length === 0) continue;
        let pick = dolls[i].pop();
        if (pick === basket[basket.length - 1]){
            basket.pop();
            answer += 2;
        }
        else {
            basket.push(pick);
        }
    }
    return answer;
}

console.log(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]], [1,5,3,5,1,2,1,4]));
