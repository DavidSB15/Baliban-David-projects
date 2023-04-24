const username = document.getElementById('username');
const saveScoreBtn = document.getElementById('saveScoreBtn');
const finalScore = document.getElementById('finalScore');
const mostRecentScore = localStorage.getItem('mostRecentScore');

const highScores = JSON.parse(localStorage.getItem('highScores')) || [];

const MAX_HIGH_SCORES = 5;

finalScore.innerText = mostRecentScore;

username.addEventListener('keyup', () => {
    saveScoreBtn.disabled = !username.value;
});

saveHighScore = (e) => {
    e.preventDefault();

    const score = {
        score: mostRecentScore,
        name: username.value,
    };
    highScores.push(score);
    highScores.sort((a, b) => b.score - a.score);
    highScores.splice(5);

    localStorage.setItem('highScores', JSON.stringify(highScores));
    window.location.assign('/');
};

// define the medal thresholds
const goldThreshold = 30;
const silverThreshold = 20;
const bronzeThreshold = 10;

// function to assign medal based on score
function assignMedal(score) {
  if (score >= goldThreshold) {
    return "🥇";
  } else if (score >= silverThreshold) {
    return "🥈";
  } else if (score >= bronzeThreshold) {
    return "🥉";
  } else {
    return "";
  }
}

function appendHighScore(name, score) {
  const medal = assignMedal(score);
  
  const listItem = document.createElement("li");
  listItem.innerText = `${name}: ${score} ${medal}`;
  
  const highScoreList = document.getElementById("highScoreList");
  highScoreList.appendChild(listItem);
}

const score = Math.floor(Math.random() * 100) + 1;

appendHighScore(name, score);
