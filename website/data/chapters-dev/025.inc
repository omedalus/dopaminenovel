<div class="chapsection"><div class="computer email"><br/>
<strong>Bug#:</strong> 7392252 <br/>
<strong>Submitted by:</strong> ssrinivanasan<br/>
<strong>Assigned to:</strong> awolfson<br/>
<strong>Priority:</strong> P1<br/>
<br/>
<strong>Title:</strong> Network handler corrupts player inventory<br/>
<strong>Description:</strong> The Player class’s getInventory accessor returns a pointer to Inventory object, instead of scoped reference with a mutex lock as I have recommended. At PlayerNetworkHandler.cpp:2163, awolfson creates a possible race condition between the network and UI threads. If a player can induce concurrent writes, random items will appear in their inventory (demonstrated in unit test #12271).<br/>
<br/>
<strong>Comments: </strong><br/>
<strong>ssrinivanasan</strong><br/>
If the dev team would take my design advice then they would not have these bugs in the first place.<br/>
<br/>
<strong>awolfson</strong><br/>
First of all, there’s no way a user would be able to make this happen. Second, it’s not the player’s real inventory that’s affected, only their client-side snapshot. It self-corrects during the next state pull. Yes, this is a bug, but it’s a very minor one.<br/>
<strong>Priority changed from P1 to P3 by awolfson.</strong><br/>
<br/>
<strong>ssrinivanasan</strong><br/>
You are missing the bigger picture. The issue is not just this one bug. The issue is that you are using a bad overall software design. This bug is a natural consequence of the dev team’s unwillingness to apply the more robust architecture that I recommended. More bugs like it will continue to be filed until this changes.<br/>
<strong>Priority changed from P3 to P1 by ssrinivanasan.</strong><br/>
<br/>
---<br/>
<strong>Bug#:</strong> 7392303 <br/>
<strong>Submitted by:</strong> awolfson<br/>
<strong>Assigned to:</strong> ssrinivanasan<br/>
<strong>Priority:</strong> P1<br/>
<br/>
<strong>Title:</strong> Stick lodged in Satish’s butt again<br/>
<strong>Description:</strong> As evidenced by Bug Report #7392252, it is clear that Satish has once again sat down on a large metal rod, which must be removed from his rectum immediately.<br/>
<br/>
<strong>Comments: </strong><br/>
<strong>ssrinivanasan</strong><br/>
Real mature. Need I remind you that this is grossly inappropriate use of company’s bug-tracking database.<br/>
<br/>
<strong>awolfson</strong><br/>
I know you are but what am I?<br/>
<br/>
<strong>ssrinivanasan</strong><br/>

<div class="formcommentbox">
  <br/>
  <br/>
  <br/>
</div>

<br/>
</div>
<p>
Satish stared apoplectically at the comment entry field. He furtively began several attempted responses, only to delete them as he searched for the right words to express his righteous indignation. He swore to himself that he would find a way to make lead developer Aaron Wolfson feel his wrath.
</p>
<p>
He was so embroiled in the flame war that he didn’t notice someone enter his office until he heard the door close.
</p>
<p>
Satish looked up from his monitor. The first thing he saw was a large cardboard box. The second thing he noticed was the man holding it.
</p>
<p>
“Danny?” Satish said, unhappily surprised.
</p>
<p>
“Hey.” Danny dropped the box casually to the floor. It fell lightly.
</p>
<p>
Satish eyed the box. “What’s that?”
</p>
<p>
“This?” Danny idly kicked it around with his toe. “Oh, this is nothing. It’s empty. I pulled it out of a recycling bin behind Building 34.”
</p>
<p>
Satish shook his head in annoyed bewilderment. “What the hell are you doing here? I thought we were finished.”
</p>
<p>
“I thought so too,” said Danny. 
</p>
<p>
“How did you even get inside the building? Do you have a visitor’s badge? Are you just walking around on Microsoft property alone?” Satish pressed.
</p>
<p>
“Oh, yeah, that,” Danny said nonchalantly. “Do you know what I just discovered a few minutes ago? If you’re standing outside a doorway carrying a large, heavy-looking box and you act like you’re struggling to grab the door handle, then not only will people not bother asking for ID, they’ll even hold the doors open for you. True story!”
</p>
<p>
Satish placed his hand threateningly on his desktop telephone. “I could have you arrested.”
</p>
<p>
Danny smiled calmly. “After everything that's happened in the last twenty-four hours, I find your attempts at intimidation rather un-compelling.”
</p>
<p>
Irritated, Satish limply drew back his hand and crossed his arms. “So, to what do I owe the supreme pleasure of seeing you again?”
</p>
<p>
Danny sat down in a plastic chair beside the desk, near a bookshelf packed with reference manuals. Satish’s office was a dense, efficient work environment, with whiteboards, books, and paper trays organized with the intricacy of clockwork. Design documents hung pinned from corkboards, and large poster-sized software architecture diagrams lined the walls. Scarcely a single cubic inch of volume was spared in the baroque machinery of intellectual productivity.
</p>
<p>
 “It appears,” said Danny, “that our little project last night had some extremely unfortunate consequences.”
</p>
<p>
“No shit,” said Satish. “One of my friends is lying in a hospital bed right now with his head almost caved in.”
</p>
<p>
Danny looked away contritely. “He’s not the only one who got hurt because of what happened last night.”
</p>
<p>
“Oh please, if you're talking about that little scratch on your back, spare me,” Satish scolded. “Your pity-point account has a balance of zero.”
</p>
<p>
“Me? No. Geez. I'm not talking about myself, Satish.”
</p>
<p>
“Then who are you talking about?” Satish pressed.
</p>
<p>
“Do you remember the drug lord we talked to on the phone? Sergey Mukhayev?” Danny asked.
</p>
<p>
“Yes, of course,” said Satish.
</p>
<p>
“He found me,” said Danny.
</p>
<p>
A moment of silence passed between the two men. Satish’s face was a complex mixture of shock, contempt, and sympathy. He said nothing.
</p>
<p>
“There’s some kind of Russian mob war,” Danny explained. “Some kingpin kidnapped his daughter. He’s staying at the Medina Gallante hotel. Sergey tracked me down, and is demanding that I join him to rescue her.”
</p>
<p>
Another silent moment passed. Satish stared at him, wordless.
</p>
<p>
“I need your help, Satish,” Danny said.
</p>
<p>
After a long, tense pause, Satish replied, “Okay.”
</p>
<p>
Danny was taken aback. “Really?”
</p>
<p>
“Yes,” Satish said with a cold nod. 
</p>
<p>
“Just like that?” Danny asked eagerly.
</p>
<p>
“Yes,” Satish repeated. “Look. I can’t stand you. And if you ask me, you’re getting what you deserve. But there’s a big difference between hating you and letting you get killed. So, yes, I’ll help.”
</p>
<p>
Danny smiled warmly. “Thank you, Satish. I mean that. Despite everything between us, I know you’re a good man.”
</p>
<p>
Businesslike, Satish asked, “Now, is your passport valid?”
</p>
<p>
Danny shook his head. “My… What?”
</p>
<p>
“Flights from Sea-Tac to Chhatrapati Shivaji take between twenty to thirty hours,” Satish told him. “You can get a visa on arrival, so entering the country will be no problem. I have a brother that can meet you at the airport. He runs an English-language call center just outside of Mumbai. He will be able to set you up with an IT job. It won’t pay much by American standards, but the money will go far in India. He’ll let you stay at his house until you get settled in. Now, as for the plane trip, if you buy a one-way ticket for immediate departure, you’ll ring alarm bells, so what you should…”
</p>
<p>
“Whoa, Satish, stop!” Danny interrupted. “I’m not fleeing the country.”
</p>
<p>
“Then why else would you come to me?”
</p>
<p>
Danny reached into his pocket and withdrew his data stick.
</p>
<p>
“I got the source code to the Medina Gallante’s security and hotel management systems,” he said. “I need your help to find an exploitable vulnerability, and to use it to crack into their computers. And I’d like to do it tonight.”
</p>
<p>
Satish stuttered while trying to respond. “Don’t be silly, Danny. You don’t have to do that. You can get out of this.”
</p>
<p>
“I want to do it,” Danny insisted. “I’m choosing to.”
</p>
<p>
“Have you completely lost your mind?” said Satish.
</p>
<p>
Danny smiled gently. “Quite the contrary. I think I’ve finally begun to find it.”
</p>
<p>
“Danny, I’m not getting involved in another psychotic scheme with you!”
</p>
<p>
Danny looked into Satish’s eyes earnestly. “If I can get Moshen and Mike and maybe Jason to help me, will you join us?”
</p>
<p>
“Fuck you!” Satish barked. “You leave them out of this! Haven’t you caused them enough problems? Whatever the hell this bullshit is about drug lords and kidnapped daughters or whatever, it’s not their fight. And it’s not yours either, for that matter.”
</p>
<p>
“I’m making it my fight,” Danny replied.
</p>
<p>
“Why the fuck would you do that?” Satish demanded.
</p>
<p>
Danny shrugged. “Why the fuck does anybody do anything?” he said.
</p>
<p>
“What could you possibly have to gain by doing this?” Satish asked.
</p>
<p>
Danny answered, “The ability to see myself as the kind of man who does this.”
</p>
<p>
Satish stared at him incredulously.
</p>
<p>
Danny simply smiled, and spoke softly. “Look, Satish. I’ve asked myself: Why did I sign up for Jason’s little excursion in the first place, anyway? I’ve got savings in the bank. I’ve got a roof over my head, food on my plate, and toys to keep me entertained. But I chose to risk everything &mdash; my comfort, my freedom, my very life &mdash; for… something else. And Jason &mdash; what was <em>he</em> trying to gain? Not money. Jason’s got plenty of money, and he’s turned out to be one of the unhappiest people I’ve ever met. Money’s just a proxy for something else, something he doesn’t have nearly enough of.
</p>
<p>
“You’re right, Satish. I could take you up on fleeing the country &mdash; a very generous and kind-hearted offer, by the way. I know I’d be alright. I’d be safe. I’d work, I’d pay my rent, I’d put food on my plate, I’d go on living like I always do. I’d survive.
</p>
<p>
“But you know what? At this point in my life, I’m far past the point of considering that a win. I <em>know</em> I can survive. I’ve already thoroughly proven that I’m a viable, productive, self-sustaining human being. I’m almost forty years old. I’ve been self-sustaining for almost twenty years &mdash; that’s enough time to create and raise an entirely new human being to the point where <em>they’re</em> viable and productive and self-sustaining in turn! Yes, in theory, I can go on merely surviving. But you know what? I won’t. I’m sick of it. I can do better. Mere survival is the bottom-most level of Maslow’s Hierarchy. I’ve earned the right &mdash; no, the <em>obligation</em> &mdash; to reach for something higher.”
</p>
<p>
Satish rolled his eyes. “And getting involved in a drug war is your idea of ‘something higher’? No pun intended.”
</p>
<p>
“By itself, no,” said Danny. “But helping someone who desperately needs me right now, someone for whom I’m the only hope… That sounds like the right track.”
</p>
<p>
Satish scoffed, “Are you talking about that Russian guy? You feel like you need to be a hero on behalf of a drug lord? Need I remind you, he’s ‘making his way’ by smuggling and selling cocaine.”
</p>
<p>
Danny laughed lightly. “Do you know what cocaine does, Satish? Biochemically, that is? It gives you a feeling of accomplishment. Just straight-up <em>gives</em> it to you. It’s no wonder so many people love the stuff so much, enough to keep guys like Sergey in business. Who needs to <em>actually</em> pursue dreams or achieve goals, when you can just get the resulting pride and satisfaction directly in powder form?
</p>
<p>
“It’s a fake feeling, of course. You can’t outsmart your own mind. You yourself know perfectly well whether or not you’ve achieved your own goals, because you’re the one that defines those goals in the first place.
</p>
<p>
“You know, I’ve been trying to pay attention to all the technical molecular biology stuff I’ve been hearing ever since this whole thing started; and the truth is, I haven’t been able to grasp much. But do you know what I <em>do</em> get? That the brain chemical affected by cocaine &mdash; dopamine &mdash; is a real, measurable, quantifiable substance, and on a molecular level it plays a predictable, deterministic, almost mundane role in the brain’s circuitry for pleasure and reward. It’s a critical part of how the human brain works, and there’s absolutely nothing magical about it. When you understand how the components work, it becomes possible to analyze thoughts flowing through a human mind the same way you can analyze instructions flowing through a computer’s CPU. When a neurobiologist talks about what motivates a person, how a person perceives the world and acts on their wants and needs and dreams and desires… When you talk about that stuff armed with an actual knowledge of how the machinery of the brain operates, you’re not talking philosophy. You’re talking engineering.
</p>
<p>
“And dopamine isn’t simply a reward signal. It’s also part of the brain’s circuitry for perception and action. Maybe it’s all interrelated. Maybe you need to have a reward system by definition in order to be able to take action &mdash; no action would occur if there was no reinforcement process to shape it. And you need perception in order to recognize when to dole out a reward, to recognize when that reinforcement is supposed to kick in. It all fits together, like an incredibly intricate circuit diagram.
</p>
<p>
“Look, I’m just a Gen-X dot-com code-monkey. Ask me to fiddle with a man-made machine? I can do that. Ask me to decipher the secrets of how the human mind arises from its physical substrates? Hell, man. I’m not that smart.
</p>
<p>
“But you know what I <em>am</em> smart enough to do? Code. I’ve been programming since my hands could span a keyboard. Computers and I grew up together. I’m among the first-born children of the Information Age. I might not know anything about the machinery of the brain or the mechanics of consciousness, but I do know that if you give me the schematics for an information processing system, I can bend it to my will.
</p>
<p>
“And it’s about time I took those skills and applied them back upon the mind that they arise from.
</p>
<p>
“For my whole life I’ve been miserable &mdash; constantly lamenting my choices, imagining I had chosen different paths, daydreaming what my life would be like in alternate universes. Never once letting myself feel joy in the universe I’m actually living in, in the life I’ve actually chosen.
</p>
<p>
“That ends today.
</p>
<p>
“I have the power to <em>reprogram myself</em>. I can stop denying myself the well-earned privilege of taking pride in who I am. I can recognize myself as someone worthy of admiration. And when I look in a mirror, I can learn to perceive my own face as the face of a man.
</p>
<p>
“And I accomplish that by acting like one.”
</p>
<p>
Danny laid the thin data stick on Satish’s desk, and slid it forcefully toward him.
</p>
<p>
“Now, please help me do that,” Danny said.
</p>
<p>
Satish’s face boiled with disapproval. He shook his head, made dismissive gestures, and emitted a few grunts. Several times he opened his mouth ready to offer a retort or a jab, but every time only a fraction of a syllable would come out. Eventually his resistance grew less animated, and he turned away from Danny to brood in quiet contemplation at his desk.
</p>
<p>
Finally, his hand moved toward the data stick lying on his desk.
</p>
<p>
After several long, silent moments, he said to Danny without turning toward him, “You can’t reverse engineer an entire deployed customer solution in a matter of hours.”
</p>
<p>
Danny sighed. “You haven’t even looked at the code yet.”
</p>
<p>
“I don’t need to,” Satish insisted. “It can’t be done. And besides, even if we write a successful exploit &mdash; a virus or a trojan of some kind &mdash; it’s still not clear how we would deliver it to the Medina Gallante’s computer systems…”
</p>
<p>
Sharply and with a hint of anger, Danny barked, “Satish! Stop figuring out why it can’t be done, and start figuring out how to do it.”
</p>
<p>
Satish opened his mouth to say something but stopped himself. Several silent seconds passed as he sat with a hateful frown, slowly tapping the data stick on his desk.
</p>
<p>
Finally, he spun in his chair, swung the data stick toward his workstation, and plugged it into a USB port.
</p>
<p>
“First thing we can do,” Satish said, opening brightly colored windows on his computer screen, “is search through all comments in the source code.”
</p>
<p>
Danny rocked forward excitedly in his chair. “Now you’re talking!”
</p>
<p>
“We’ll look for lines marked, ‘TODO’,” Satish explained. “A lot of times programmers will leave notes for themselves to clean up a bad piece of code. If they’re working toward a deadline and they have to add a new feature to the software quickly, usually they’ll write a very sloppy, unreliable version of that feature first, with the intent to come back and fix it later when they have more time. But they forget, or they run out of time, so the rough draft ends up getting deployed at the customer site.”
</p>
<p>
Heartened, Danny stood and marched over to Satish’s whiteboard. With a brisk nod, he grabbed a dry-erase marker. “Let’s enumerate the system’s external points of contact,” he said, listing as he spoke. “There’s the billing subsystem. The VOIP telephone subsystem. The police alarm subsystem…”
</p>
<p>
“This source code includes their unit tests and build verification tests,” Satish said as blocks of text slid across his screen. “I can run a code coverage analysis of their internal testing suite. It will highlight portions of code that their own quality assurance systems maybe failed to test properly. If there are any bugs in the code’s low-coverage areas, the engineers would’ve missed them. …Danny?”
</p>
<p>
“Yeah?”
</p>
<p>
“Pull up a chair,” Satish invited.
</p>
<p>
Danny gave a heartfelt, grateful nod.
</p>
<p>
Satish stared at the myriad grids of data on his screen. “This is going to take a lot of work,” he warned. “But I think it can be done.”
</p>
</div>