function closer(number, left, right, answer){
    let x = Math.floor((number - 1) / 3), y = Math.floor((number - 1) % 3);
    let leftDist = Math.abs(Math.floor((left - 1) / 3) - x) + Math.abs(((left - 1) % 3) - y);
    let rightDist = Math.abs(Math.floor((right - 1) / 3) - x) + Math.abs(((right - 1) % 3) - y);
    if (leftDist > rightDist) return 'R';
    else if (leftDist < rightDist) return 'L';
    else if (leftDist == rightDist) return false;
}

function solution(numbers, hands) {
	let answer = "";
    let left = 10, right = 12;
	for (let n of numbers) {
		if (n === 1 || n === 4 || n === 7){
            left = n;
            answer += 'L';
        }
        else if (n === 3 || n === 6 || n === 9){
            right = n;
            answer += 'R';
        }
        else if (n === 2 || n === 5 || n === 8 || n === 0){
            if (n === 0) n = 11;
            let c = closer(n, left, right, answer)
            if (c == 'L'){
                left = n;
                answer += 'L';
            }
            else if (c == 'R'){
                right = n;
                answer += 'R'
            }
            else {
                if (hands == "right"){
                    right = n;
                    answer += 'R';
                }
                else if (hands == "left"){
                    left = n;
                    answer += 'L';
                }
            }
        }
	}
    return answer;
}
