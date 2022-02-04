function calculate(priority, numbers, oprs){
    let numbers_ = numbers.slice();
    let oprs_ = oprs.slice();
    for(let opr of priority){
        for(let i = 0; i < oprs_.length; i++) {
            if (opr === oprs_[i]) {
                if (opr === 1){
                    numbers_[i] += numbers_[i + 1];
                }
                else if (opr === 2){
                    numbers_[i] -= numbers_[i + 1];
                }
                else if (opr === 3){
                    numbers_[i] *= numbers_[i + 1];
                }
                numbers_.splice(i + 1, 1);
                oprs_.splice(i, 1);
                i--;
            }
        }
    }
    return Math.abs(numbers_[0]);
}

function solution(expression) {
    var answer = 0;
    let regExp = /[0-9]+/g;
    let priority = [0,0,0];
    let numbers = expression.match(regExp).map(x => {
        return parseInt(x);
    });
    regExp = /\D/g;
    let oprs = expression.match(regExp).map(x => {
        switch(x){
            case '+':
                return 1;
            case '-':
                return 2;
            case '*':
                return 3;
        }
    });

    for(let i = 1; i <= 3; i++) {
        priority[0] = i;
        for(let j = 1; j <= 3; j++) {
            if (priority.includes(j)) continue;
            priority[1] = j;
            for(let k = 1; k <= 3; k++){
                if (priority.includes(k)) continue;
                priority[2] = k;
                let res = calculate(priority, numbers, oprs);
                answer = res > answer ? res : answer;
                priority[2] = 0;
            }
            priority[1] = 0;
        }
        priority[0] = 0;
    }
    return answer;
}
