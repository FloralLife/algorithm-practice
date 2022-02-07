function canFinish(limit, n, times) {
  const finishCnt = times.reduce(
    (prev, cur) => prev + Math.floor(limit / cur),
    0
  );
  return finishCnt >= n;
}

function solution(n, times) {
  let low = 0;
  let high = Math.max(...times) * n;

  while (low < high) {
    const limit = Math.floor((low + high) / 2);
    if (canFinish(limit, n, times)) high = limit;
    else low = limit + 1;
  }

  return low;
}
