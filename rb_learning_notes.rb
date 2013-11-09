#!/usr/bin/env ruby

#-----------------------
# everything is object
# 点号之前的东西称为接收者，点号后面的名字是被调用的方法
# 方法通过向对象发送消息来唤起调用

def hello(name)
  "Hello, #{name.capitalize}"
end

puts hello('levin')
puts 'levin'.length
puts -8.abs
puts 'levin'.index('v')

#-----------------------
# array literal

words_array = ['cat', 'dog']
puts words_array

words_array = %w{cat dog}
puts words_array

#-----------------------
# hash literal
# 此处和php数组一样的结构

words_hash = {
  'a' => 'hello',
  'b' => 'world',
}

puts words_hash

#-----------------------
# control structures

if 5 > 3
  puts 'ret 1'
elsif 5 == 3
  puts 'ret 2'
else
  puts 'ret 3'
end

puts 'hello' if 1

square = 2
square = square*square while square < 100
puts square

#-----------------------
# regex

if 'ruby' =~ /r\w*y/
  puts 'match'
end

puts 'python'.sub(/python/, 'ruby')
puts 'pythonpython'.gsub(/python/, 'ruby')

#-----------------------
# block yield
# 迭代数组的内容，在each等方法中肯定使用了yield

def call_block
  yield('hello')
end

call_block { | word | puts word }

words_array.each { | word | puts word }

5.times { print '*' }

3.upto(6) { |i| print i }

('a'..'e').each { |char| print char }

#-----------------------
# printf

printf("\nNum: %3.2f, String: %s\n", 237844.248, 'hello')

#-----------------------
# class object
# 创建对象时首先在内存中保存未初始化的对象，然后调用对象的initialize方法
# @符号开头的变量为实例变量，每个对象都有实例变量的拷贝
# 子类继承方法时，应该是增量，而不是直接检验或使用父类的实例变量(低耦合)

class Song
  
  attr_reader :name, :artist, :duration
  
  attr_writer :duration
  
  @@play_count = 0
  
  def initialize(name, artist, duration)
    @name = name
    @artist = artist
    @duration = duration
    @play_count = 0
  end

  def to_s
    "#@name, #@artist (#@duration)"
  end
  
  def play
    @@play_count += 1
    @play_count += 1
    "#@play_count plays, total #@@play_count plays"
  end
  
end

song = Song.new('ruby', 'ruby song', 240)
puts song.inspect
puts song.to_s

class OKSong < Song
  
  attr_reader :lyrics
  
  def initialize(name, artist, duration, lyrics)
    super(name, artist, duration)
    @lyrics = lyrics
  end

  def to_s
    super + " lyrics: #@lyrics"
  end

end

song = OKSong.new('ruby', 'ruby song', 240, 'ruby song lyrics')
puts song.inspect
puts song.to_s
puts song.name
puts song.lyrics
puts song.duration
song.duration = 301
puts song.duration
puts song.play
puts song.play

class SongList
  
  MAX_TIME = 300
  
  def SongList.is_too_long(song)  #如果没加类名前缀，直接调用将提示没有这个方法
    return song.duration > MAX_TIME
  end
  
end

puts SongList.is_too_long(song)

#-----------------------




