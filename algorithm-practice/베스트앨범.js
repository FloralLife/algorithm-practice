function solution(genres, plays) {
  const count = [];
  for (let i = 0; i < genres.length; i++) {
    const g = count.find((c) => c.genre === genres[i]);
    if (g === undefined)
      count.push({
        genre: genres[i],
        cnt: plays[i],
        songs: [{ idx: i, plays: plays[i] }],
      });
    else {
      g.cnt += plays[i];
      g.songs.push({ idx: i, plays: plays[i] });
    }
  }
  const rank = count.sort((a, b) => b.cnt - a.cnt);
  const answer = rank.reduce((ans, r) => {
    const songs = r.songs.sort((a, b) => {
      if (b.plays === a.plays) return a.idx - b.idx;
      return b.plays - a.plays;
    });
    ans = [...ans, songs[0].idx];
    if (songs.length >= 2) ans.push(songs[1].idx);
    return ans;
  }, []);
  return answer;
}
