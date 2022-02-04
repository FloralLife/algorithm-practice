function isMatch(user, banned){
    if (banned.length !== user.length) return false;
    for(let i = 0; i < banned.length; i++) {
        if (banned[i] === '*') continue;
        if (banned[i] !== user[i]) return false;
    }
    return true;
}

function sanction(user_id, banned, contain) {
    let sanc = [];
    for(let u = 0; u < user_id.length; u++){
        let user = user_id[u];
        if (isMatch(user, banned)){
            sanc.push(u);
            contain[u]++;
        }
    }
    return sanc;
}

function dfs(n, sancList, isMapping, prev, contain){
    if (n === sancList.length) {
        return 1;
    }
    if (sancList[n].length === 0)
        return dfs(n+1, sancList, isMapping);
    let cnt = 0;
    for (let i = 0; i < sancList[n].length; i++){
        if (isMapping[sancList[n][i]] || (contain[sancList[n][i]] !== 1 && sancList[n][i] <= prev)) continue;
        isMapping[sancList[n][i]] = true;
        cnt += dfs(n+1, sancList, isMapping, sancList[n][i], contain);
        isMapping[sancList[n][i]] = false;
    }
    return cnt;
}

function solution(user_id, banned_id) {
    var answer = 0;
    let sancList = [];
    let contain = new Array(user_id.length).fill(0);
    for(let banned of banned_id){
        sancList.push(sanction(user_id, banned, contain));
    }

    let isMapping = new Array(user_id.length).fill(false);
    console.log(contain[3]);
    console.log(sancList);
    answer = dfs(0, sancList, isMapping, -1, contain);
    return answer;
}

console.log(solution(	["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "abc1**"]));
