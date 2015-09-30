<div class="chapsection"><div class="computer email"><br/>
<strong>Bug#:</strong> 7392252 <br/>
<strong>Submitted by:</strong> ssrinivanasan<br/>
<strong>Assigned to:</strong> awolfson<br/>
<strong>Priority:</strong> P1<br/>
<br/>
<strong>Title:</strong> Network handler corrupts player inventory<br/>
<strong>Description:</strong> The Player class’s getInventory accessor returns a pointer to Inventory object, instead of scoped reference with a mutex lock. At PlayerNetworkHandler.cpp:2163, there is a race condition between the network and UI threads. If a player can induce concurrent writes, random items will appear in their inventory (demonstrated in unit test #12271).<br/>
</div>
<p>
Satish typed details of the defect into the bug tracker. He was so engrossed in providing a thorough and accurate bug description that he didn’t notice someone enter his office until he heard the door close. He looked up from his monitor. The first thing he saw was a large cardboard box. The second was the man holding it. “<em>Danny?</em>”
</p>
<p>
“Hey.” Danny dropped the box. It fell lightly.
</p>
<p>
Satish eyed the box. “What’s that?”
</p>
<p>
“This?” Danny idly kicked it with his toe. “Oh, nothing. It’s empty. I pulled it out of a recycling bin behind Building 34.”
</p>
<p>
Satish shook his head. “How did you get inside the building? Do you have a visitor’s badge? Are you just walking around on Microsoft property without an escort?”
</p>
<p>
“Do you know what I just discovered a few minutes ago?” Danny said nonchalantly. “If you’re standing outside a doorway carrying a large, heavy-looking box and you act like you’re struggling to grab the door handle, then not only will people <em>not</em> ask you for ID, they’ll even hold the doors open for you.”
</p>
<p>
Satish crossed his arms. “What are you doing here?”
</p>
<p>
Danny sat down in a plastic chair beside the desk, near a bookshelf packed with reference manuals. Satish’s office was a dense, efficient work environment, with whiteboards, books, and paper trays organized with the intricacy of clockwork. Design documents hung pinned from corkboards, and large poster-sized software architecture diagrams lined the walls. Scarcely a single cubic inch was spared in the baroque machinery of intellectual productivity.
</p>
<p>
“It appears,” said Danny, “that our project last night had some unfortunate consequences.”
</p>
<p>
“No shit,” said Satish. “My friend is lying in a hospital bed right now with his head almost caved in.”
</p>
<p>
Danny looked away contritely. “It’s more than that. The drug lord &mdash; Sergey Mukhayev. He found me.”
</p>
<p>
A moment of silence passed between the two men. Satish’s face was a complex mixture of shock, contempt, and sympathy.
</p>
<p>
“There’s some kind of Russian mob war,” Danny explained. “Some kingpin kidnapped his daughter. He’s staying at the Medina Gallante hotel. Sergey is demanding that I join him to rescue her.”
</p>
<p>
Satish stared at him, wordless.
</p>
<p>
“I need your help,” Danny said.
</p>
<p>
After a long pause, Satish replied, “Okay.”
</p>
<p>
“Really?” Danny asked, relieved. “Just like that?”
</p>
<p>
“Yes,” Satish replied. “Look. I think you’re kind of clueless, but that doesn’t mean I want you killed. So, yes, I’ll help.”
</p>
<p>
“Thank you,” Danny said humbly.
</p>
<p>
Satish asked, “Now, is your passport valid?”
</p>
<p>
Danny shook his head. “My… What?”
</p>
<p>
“Flights from Sea-Tac to Chhatrapati Shivaji take between twenty to thirty hours,” Satish told him. “You can get a visa on arrival, so entering India will be no problem. I have a brother that can meet you at the airport. He runs an English-language call center in Mumbai. I’ll ask him to set you up with a job. It won’t pay much by American standards, but the money will go far in Maharashtra. Now, as for buying the plane ticket…”
</p>
<p>
“Whoa, Satish, stop!” Danny interrupted. “I’m not fleeing the country.”
</p>
<p>
“Then why else would you come to me?”
</p>
<p>
Danny reached into his pocket and withdrew his data stick. “I got the source code to the Medina Gallante’s security and hotel management systems. I need your help to find a vulnerability and crack into their computers. And we need to do it right now.”
</p>
<p>
“Don’t be silly, Danny. You don’t have to do that. You can get out of this.”
</p>
<p>
“I <em>want</em> to do it,” Danny insisted. “I’m <em>choosing</em> to.”
</p>
<p>
“Have you completely lost your mind?” said Satish.
</p>
<p>
Danny smiled gently. “Quite the contrary. I think I’ve finally begun to find it.”
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
Danny simply smiled, and spoke softly. “Look, Satish. I’ve asked myself: Why did I sign up for Jason’s little excursion in the first place, anyway? I’ve got savings in the bank. I’ve got a roof over my head, food on my plate, and toys to keep me entertained. But I chose to risk everything &mdash; my comfort, my freedom, my very life &mdash; for… something else. And Jason &mdash; what was <em>he</em> trying to gain? Not money. Jason’s got plenty of money, and he’s one of the most unhappy people I’ve ever met. Money’s just a proxy for something else, something he doesn’t have nearly enough of.
</p>
<p>
“You’re right, Satish. I could take you up on fleeing the country &mdash; a very generous and kind-hearted offer, by the way. I know I’d be alright. I’d be safe. I’d work, I’d pay my rent, I’d put food on my plate, I’d go on living like I always do. I’d survive.
</p>
<p>
“But you know what? At this point in my life, I’m far past the point of considering that a win. I <em>know</em> I can survive. I’ve already thoroughly proven that I’m a viable, productive, self-sustaining human being. Yes, I can go on merely surviving. But you know what? I won’t. I’m sick of it. I can do better. Mere survival is the <em>bottom</em> of Maslow’s Hierarchy. I’ve earned the right &mdash; no, the <em>obligation</em> &mdash; to reach for something higher.”
</p>
<p>
“And getting involved in a drug war is your idea of ‘something higher’?” said Satish. “No pun intended.”
</p>
<p>
“By itself, no,” said Danny. “But helping someone who desperately needs me right now, someone for whom I’m the only hope… That sounds like the right track.”
</p>
<p>
Satish scoffed, “Are you talking about that Russian guy? You feel like you need to be a hero on behalf of a cocaine smuggler?”
</p>
<p>
Danny laughed lightly. “Do you know what cocaine does, Satish? Biochemically, that is? It gives you a feeling of accomplishment. Just straight-up <em>gives</em> it to you. It’s no wonder people love the stuff so much, enough to keep guys like Sergey in business. Who needs to <em>actually</em> pursue dreams or achieve goals, when you can just get the resulting pride and satisfaction directly in powder form?
</p>
<p>
“It’s a fake feeling, of course. You can’t outsmart your own mind. You yourself know perfectly well whether or not you’ve achieved your own goals, because you’re the one that defines those goals in the first place.
</p>
<p>
“You know, I’ve been trying to pay attention to all the technical molecular biology stuff I’ve been hearing ever since this whole thing started. You know what I get? That the brain chemical affected by cocaine &mdash; dopamine &mdash; is a real, measurable, quantifiable substance, and on a molecular level it plays a predictable, deterministic role in the brain’s circuitry. It’s a critical part of how the human brain works, and there’s absolutely nothing magical about it. When you understand how the components work, it becomes possible to analyze thoughts flowing through a human mind the same way you can analyze instructions flowing through a computer’s CPU. When a neurobiologist talks about what motivates a person, how a person perceives the world and acts on their wants and needs and dreams and desires… When you talk about that stuff armed with actual knowledge of how the machinery of the brain operates, you’re not talking philosophy. You’re talking engineering.
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
“For my whole life I’ve been miserable &mdash; constantly lamenting my choices, imagining I had chosen different paths, daydreaming what my life would be like in alternate universes.
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
Danny laid the data stick on Satish’s desk, and slid it forcefully toward him.
</p>
<p>
“Now, please help me do that,” Danny said.
</p>
<p>
Satish’s face boiled with disapproval. He shook his head and made dismissive gestures. Eventually he turned away from Danny to brood in quiet contemplation. Slowly, his hand moved toward the data stick lying on his desk. He tapped it against his desk. Finally, he spun in his chair, swung the data stick toward his workstation, and plugged it into a USB port.
</p>
<p>
“First thing we can do,” Satish said, opening colorful windows on his computer screen, “is search through all comments in the source code.”
</p>
<p>
Danny grinned.
</p>
<p>
“We’ll look for lines marked, ‘TODO’,” Satish explained. “A lot of times programmers will leave notes for themselves to clean up a bad piece of code. If they’re working toward a deadline and they have to add a new feature quickly, usually they’ll write a sloppy, unreliable version first, with the intent to come back and fix it later when they have more time. Which, of course, they never do.”
</p>
<p>
Heartened, Danny marched over to Satish’s whiteboard and grabbed a dry-erase marker. “Let’s enumerate the system’s external points of contact,” he said, listing as he spoke. “There’s the billing subsystem. The VOIP telephone subsystem. The police alarm subsystem…”
</p>
<p>
“This source code includes their unit tests and build verification tests,” Satish said as blocks of text slid across his screen. “I can run a code coverage analysis of their internal testing suite. It will highlight portions that their own quality assurance systems failed to test properly. If there are any bugs in the code’s low-coverage areas, the engineers would’ve missed them. …Danny?”
</p>
<p>
“Yeah?”
</p>
<p>
“Pull up a chair,” Satish invited. “This is going to take a lot of work… But I think it can be done.”
</p>
</div>