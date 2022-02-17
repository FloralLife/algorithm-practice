function getMaster(i, groupMaster) {
  let master = i;
  while (master !== groupMaster[master]) {
    master = groupMaster[master];
  }
  return master;
}

function joinGroup(newIsland, target, groupMaster, graph) {
  const targetMaster = getMaster(target, groupMaster);

  const [smaller, bigger] = [targetMaster, newIsland].sort((a, b) => a - b);

  groupMaster[bigger] = smaller;

  graph[bigger].forEach((elem, idx) => {
    if (elem === 0 || idx === smaller) return;
    if (graph[smaller][idx] === 0 || graph[smaller][idx] > elem)
      graph[smaller][idx] = elem;
  });
}

function solution(n, costs) {
  let answer = 0;

  const graph = Array.from(Array(n), () => Array(n).fill(0));
  for (const cost of costs)
    graph[cost[0]][cost[1]] = graph[cost[1]][cost[0]] = cost[2];

  const groupMaster = graph.map((e, i) => i);

  while (!groupMaster.every((elem) => getMaster(elem, groupMaster) === 0)) {
    for (let i = 0; i < n; i++) {
      if (getMaster(i, groupMaster) !== i) continue;
      let min = -1,
        target = -1;
      for (const [idx, cost] of graph[i].entries()) {
        if (
          cost !== 0 &&
          i !== getMaster(idx, groupMaster) &&
          (min === -1 || min > cost)
        ) {
          min = cost;
          target = idx;
        }
      }
      if (target === -1) continue;
      joinGroup(i, target, groupMaster, graph);
      answer += min;
    }
  }
  return answer;
}
