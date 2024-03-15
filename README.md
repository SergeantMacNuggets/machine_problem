<h1>Follow this set of commands if you're the leader of the group</h1>
<img height="100px" src="https://media.tenor.com/XspBG6ecOnUAAAAM/warhammer-warhammer40k.gif">
<h2>1. Install git form this link:</h2>
<a href="https://git-scm.com/downloads"> Git Download </a>

<h2 style="background-color:blue;">2. After installing search git bash or use cmd or powershell then create a profile by using this command</h2>
<li>git config --global user.name "Your Name"</li>
<li>git config --global user.email "your@email.com"</li>

<h2>3. Initiailizing a repository</h2>
<li>git init</li>

<h2>4. Status</h2>
<p>To identify what file is being tracked</p>
<li>git status</li>

<h2>5. If there is nothing to commit you can start by adding files to track</h2>
<li>git add filename.c</li>
<br>
<p>To add multiple files:</p>
<li>git add filename1.c filename2.c</li>

<h2>6. Staging and committing code</h2>
<p>After naa moy gi change then start comitting "commit is a process that officially changes on the added repository" (Murag Save sa imong gi edit)</p>
<li>git commit -m "I change something"</li>

<h3>Checkout</h3>
<p>Undo the process or go back to a specific time of code</p>
<li>git checkout "commit-hash"</li>
<p>Example (the yellow text after commit are the hash): </p>
<img height="200px" src="https://camo.githubusercontent.com/49bd6259b77918d8b038d212912a31242a2af0b258f8255a996791b3b67b92c8/687474703a2f2f692e696d6775722e636f6d2f487931396a4b442e706e67">

<h3>Branches</h3>
<p>A variety of your codes (Murag duplicates para pang backup)</p>
<li>git branch "new-branch-name"</li>

<h2>To upload your repositories on github follow this</h2>
<h3>1. Create a github account</h3>
<h3>2. Go to this website <a href="https://github.com/new">https://github.com/new</a></h3>
<h3>3. Fill all the required information</h3>
<h3>4. A quick setup guide will popup and choose what option who you like to choose</h3>
<p>If your folder has already been created you can input this following command</p>
<li>git remote add origin "Your url provided by github"</li>
<li>git branch -M main</li>
<li>git push -u origin main</li>
