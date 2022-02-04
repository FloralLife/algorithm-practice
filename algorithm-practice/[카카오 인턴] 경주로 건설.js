const dx = [-1,0,1,0];
const dy = [0,1,0,-1];

function Car(x, y, d, cost) {
    this.x = x;
    this.y = y;
    this.d = d;
    this.cost = cost;
}

function solution(board) {
    var answer = 0;
    let que = new Array();
    board[0][0] = 1;
    que.push(new Car(0,0,-1, 0));
    let n = 30;
    while(que.length){
        let cur = new Car(que[0].x, que[0].y, que[0].d, que[0].cost);
        que.shift();
        for(let d = 0; d < 4; d++){
            let nx = cur.x + dx[d], ny = cur.y + dy[d];
            if (nx < 0 || nx >= board.length || ny < 0 || ny >= board.length) continue;
            if (board[nx][ny] === 1) continue;
            if (board[nx][ny] === 0 || board[nx][ny] > cur.cost){
                let ncost = cur.cost + 100;
                if (cur.d !== -1 && d !== cur.d) ncost += 500;
                if (board[nx][ny] === 0 || board[nx][ny] >= ncost){
                    board[nx][ny] = ncost;
                    que.push(new Car(nx, ny, d, ncost));
                }
            }
        }
    }
    return board[board.length - 1][board.length - 1];
}
